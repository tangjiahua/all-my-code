import time
import numpy as np
import tensorflow as tf
import random
from collections import Counter
with open('/home/tangjiahua/Desktop/Homework/text8') as f:
    text = f.read()
    def preprocess(text, freq=5):
    	text = text.lower()
    	text = text.replace('.', ' <PERIOD> ')
    	text = text.replace(',', ' <COMMA> ')
    	text = text.replace('"', ' <QUOTATION_MARK> ')
    	text = text.replace(';', ' <SEMICOLON> ')
    	text = text.replace('!', ' <EXCLAMATION_MARK> ')
    	text = text.replace('?', ' <QUESTION_MARK> ')
    	text = text.replace('(', ' <LEFT_PAREN> ')
    	text = text.replace(')', ' <RIGHT_PAREN> ')
    	text = text.replace('--', ' <HYPHENS> ')
    	text = text.replace('?', ' <QUESTION_MARK> ')
    	text = text.replace(':', ' <COLON> ')
    	words = text.split()
    	word_counts = Counter(words)
    	trimmed_words = [word for word in words if word_counts[word] > freq]
    	return trimmed_words
    words = preprocess(text)

vocab = set(words)
vocab_to_int = {w: c for c, w in enumerate(vocab)}
int_to_vocab = {c: w for c, w in enumerate(vocab)}
int_words = [vocab_to_int[w] for w in words]
t = 1e-5
threshold = 0.8
int_word_counts = Counter(int_words)
total_count = len(int_words)
word_freqs = {w: c/total_count for w, c in int_word_counts.items()}
prob_drop = {w: 1 - np.sqrt(t / word_freqs[w]) for w in int_word_counts}
train_words = [w for w in int_words if prob_drop[w] < threshold]
len(train_words)

def get_targets(words, idx, window_size=5):
    target_window = np.random.randint(1, window_size+1)
    start_point = idx - target_window if (idx - target_window) > 0 else 0
    end_point = idx + target_window
    targets = set(words[start_point: idx] + words[idx+1: end_point+1])
    return list(targets)

def get_batches(words, batch_size, window_size=5):
    n_batches = len(words) // batch_size
    words = words[:n_batches*batch_size]
    for idx in range(0, len(words), batch_size):
        x, y = [], []
        batch = words[idx: idx+batch_size]
        for i in range(len(batch)):
            batch_x = batch[i]
            batch_y = get_targets(batch, i, window_size)
            x.extend([batch_x]*len(batch_y))
            y.extend(batch_y)
        yield x, y

train_graph = tf.Graph()
with train_graph.as_default():
    inputs = tf.placeholder(tf.int32, shape=[None], name='inputs')
    labels = tf.placeholder(tf.int32, shape=[None, None], name='labels')

vocab_size = len(int_to_vocab)
embedding_size = 200

with train_graph.as_default():
   embedding = tf.Variable(tf.random_uniform([vocab_size, embedding_size], -1, 1))
   embed = tf.nn.embedding_lookup(embedding, inputs)

n_sampled = 100

with train_graph.as_default():
    softmax_w = tf.Variable(tf.truncated_normal([vocab_size, embedding_size], stddev=0.1))
    softmax_b = tf.Variable(tf.zeros(vocab_size))

    loss = tf.nn.sampled_softmax_loss(softmax_w, softmax_b, labels, embed, n_sampled, vocab_size)

    cost = tf.reduce_mean(loss)
    optimizer = tf.train.AdamOptimizer().minimize(cost)

with train_graph.as_default():
    valid_size = 16 
    valid_window = 100
    valid_examples = np.array(random.sample(range(valid_window), valid_size//2))
    valid_examples = np.append(valid_examples, 
                               random.sample(range(1000,1000+valid_window), valid_size//2))

    valid_size = len(valid_examples)
    valid_dataset = tf.constant(valid_examples, dtype=tf.int32)

    norm = tf.sqrt(tf.reduce_sum(tf.square(embedding), 1, keep_dims=True))
    normalized_embedding = embedding / norm
    valid_embedding = tf.nn.embedding_lookup(normalized_embedding, valid_dataset)
    similarity = tf.matmul(valid_embedding, tf.transpose(normalized_embedding))

epochs = 10
batch_size = 1000
window_size = 10

with train_graph.as_default():
    saver = tf.train.Saver()

with tf.Session(graph=train_graph) as sess:
    iteration = 1
    loss = 0
    sess.run(tf.global_variables_initializer())
    for e in range(1, epochs+1):
        batches = get_batches(train_words, batch_size, window_size)
        start = time.time()
        for x, y in batches:
            feed = {inputs: x,
                    labels: np.array(y)[:, None]}
            train_loss, _ = sess.run([cost, optimizer], feed_dict=feed)
            loss += train_loss
            if iteration % 100 == 0: 
                end = time.time()
                print("Epoch {}/{}".format(e, epochs),
                      "Iteration: {}".format(iteration),
                      "Avg. Training loss: {:.4f}".format(loss/100),
                      "{:.4f} sec/batch".format((end-start)/100))
                loss = 0
                start = time.time()
            if iteration % 1000 == 0:
                sim = similarity.eval()
                for i in range(valid_size):
                    valid_word = int_to_vocab[valid_examples[i]]
                    top_k = 8
                    nearest = (-sim[i, :]).argsort()[1:top_k+1]
                    log = 'Nearest to [%s]:' % valid_word
                    for k in range(top_k):
                        close_word = int_to_vocab[nearest[k]]
                        log = '%s %s,' % (log, close_word)
                    print(log)
            iteration += 1

    save_path = saver.save(sess, "checkpoint/text8.ckpt")
    embed_mat = sess.run(normalized_embedding)
%matplotlib inline
%config InlineBackend.figure_format = 'retina'

import matplotlib.pyplot as plt
from sklearn.manifold import TSNE

viz_words = 500
tsne = TSNE()
embed_tsne = tsne.fit_transform(embed_mat[:viz_words, :])

fig, ax = plt.subplots(figsize=(14, 14))
for idx in range(viz_words):
    plt.scatter(*embed_tsne[idx, :], color='steelblue')
    plt.annotate(int_to_vocab[idx], (embed_tsne[idx, 0], embed_tsne[idx, 1]), alpha=0.7)

