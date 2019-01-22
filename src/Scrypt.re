open Node;

type params;

[@bs.module "scrypt"] external paramsSync : float => (~maxmem : int=?) => (~maxmemfrac : float=?) => unit => params = "paramsSync";
[@bs.module "scrypt"] external params : float => (~maxmem : int=?) => (~maxmemfrac : float=?) => unit => Reduice.Promise.t(params) = "paramsSync";

[@bs.module "scrypt"] external hash : string => params => int => string => Reduice.Promise.t(Buffer.t) = "hash";

let fixHashParams = (params) => {
    let o = Obj.magic(params);
    Obj.magic {
        "N": 2.0 ** (Js.Dict.get(o, "N") |> Belt.Option.getExn),
        "r": Js.Dict.get(o, "r") |> Belt.Option.getExn,
        "p": Js.Dict.get(o, "p") |> Belt.Option.getExn,
    };
};

let hash = (key, params, outputLength, salt) => hash(key, fixHashParams(params), outputLength, salt);