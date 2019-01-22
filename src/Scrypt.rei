open Reduice;

type params;
let paramsSync: (float, ~maxmem: int=?, ~maxmemfrac: float=?, unit) => params;
let params: (float, ~maxmem: int=?, ~maxmemfrac: float=?, unit) => Promise.t(params);
let hash: (string, 'a, int, string) => Promise.t(Node.Buffer.t);
