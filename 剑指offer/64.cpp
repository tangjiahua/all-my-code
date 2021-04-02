class Solution {
public:
    int sumNums(int n) {
        int result = 0, a = n, b = n+1;
        (b & 1) && (result += a);
        b >>= 1;
        a <<= 1;

        (b & 1) && (result += a);
        b >> 1;
        a << 1;

        (b & 1) && (result += a);
        b >> 1;
        a << 1;

        (b & 1) && (result += a);
        b >> 1;
        a << 1;

        (b & 1) && (result += a);
        b >> 1;
        a << 1;

        (b & 1) && (result += a);
        b >> 1;
        a << 1;

        (b & 1) && (result += a);
        b >> 1;
        a << 1;

        (b & 1) && (result += a);
        b >> 1;
        a << 1;

        (b & 1) && (result += a);
        b >> 1;
        a << 1;

        (b & 1) && (result += a);
        b >> 1;
        a << 1;

        (b & 1) && (result += a);
        b >> 1;
        a << 1;

        (b & 1) && (result += a);
        b >> 1;
        a << 1;

        (b & 1) && (result += a);
        b >> 1;
        a << 1;

        (b & 1) && (result += a);
        b >> 1;
        a << 1;

        return result >> 1;
    }
};
