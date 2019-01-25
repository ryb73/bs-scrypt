open Js.Promise;

Scrypt.hash("hello", Scrypt.params(1., ()), 10, "salt")
|> then_(v => {
    Js.log(v);
    resolve();
});
