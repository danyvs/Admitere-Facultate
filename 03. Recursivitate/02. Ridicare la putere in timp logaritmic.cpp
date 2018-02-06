int lgpow(int x, int pw) {
    if (pw == 1)
        return x;
    else {
        if (pw % 2 == 0)
            return lgpow(x * x, pw / 2);
        else
            return x * lgpow(x * x, (pw - 1) / 2);
    }
}
