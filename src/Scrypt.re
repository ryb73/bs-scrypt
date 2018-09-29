open Node;

type params;

[@bs.module "scrypt"] external paramsSync : float => (~maxmem : int=?) => (~maxmemfrac : float=?) => unit => params = "paramsSync";
[@bs.module "scrypt"] external params : float => (~maxmem : int=?) => (~maxmemfrac : float=?) => unit => Reduice.Promise.t(params) = "paramsSync";

[@bs.module "scrypt"] external _hashSync : string => params => int => string => Buffer.t = "hashSync";
[@bs.module "scrypt"] external _hash : string => params => int => string => Reduice.Promise.t(Buffer.t) = "hash";

let _getOpt = fun
    | Some(v) => v
    | None => Js.Exn.raiseError("Expected Some value");

let _fixHashParams = (params) => {
    let o = Obj.magic(params);
    Obj.magic {
        "N": 2.0 ** (Js.Dict.get(o, "N") |> _getOpt),
        "r": Js.Dict.get(o, "r") |> _getOpt,
        "p": Js.Dict.get(o, "p") |> _getOpt,
    };
};

let hash = (key, params, outputLength, salt) => _hash(key, _fixHashParams(params), outputLength, salt);