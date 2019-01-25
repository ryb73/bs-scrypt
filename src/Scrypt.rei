type params;
let paramsSync: (float, ~maxmem: int=?, ~maxmemfrac: float=?, unit) => params;
let params: (float, ~maxmem: int=?, ~maxmemfrac: float=?, unit) => Js.Promise.t(params);
let hash: (string, 'a, int, string) => Js.Promise.t(Node.Buffer.t);
