# 機能

- index.html: ECDH P-256(secp256r1)の公開鍵と共通鍵の生成が出来ます。
- main.c: ECDH P-256(secp256r1)の公開鍵のバリデーションが出来ます。

# 公開鍵のバリデーション

```
% gcc *.c -o main; ./main
> ECDH P-256(secp256r1)の公開鍵の16進数文字列(先頭の04を除く64バイト、128文字)を入力してEnterを押してください
b9912ca8347bd775ad087cc16d18bf07e8c5652515b5121e3a4c084a2cc7e87ebc2170c1bbf7c4b9a570794d7a8bbcc656a61cfa7419da76e5565de33176cbc5
> OK: public key is valid

> ECDH P-256(secp256r1)の公開鍵の16進数文字列(先頭の04を除く64バイト、128文字)を入力してEnterを押してください
04b9912ca8347bd775ad087cc16d18bf07e8c5652515b5121e3a4c084a2cc7e87ebc2170c1bbf7c4b9a570794d7a8bbcc656a61cfa7419da76e5565de33176cb
> NG: public key is invalid
```

# ライブラリ
- [kmackay/micro-ecc](https://github.com/kmackay/micro-ecc)