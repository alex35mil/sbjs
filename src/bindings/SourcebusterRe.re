external init : unit => unit = "" [@@bs.module "sourcebuster"];

external getFirstTyp : string = "typ" [@@bs.scope ("get", "first")] [@@bs.module "sourcebuster"];

external getFirstSrc : string = "src" [@@bs.scope ("get", "first")] [@@bs.module "sourcebuster"];

external getFirstMdm : string = "mdm" [@@bs.scope ("get", "first")] [@@bs.module "sourcebuster"];

external getFirstCmp : string = "cmp" [@@bs.scope ("get", "first")] [@@bs.module "sourcebuster"];

external getFirstCnt : string = "cnt" [@@bs.scope ("get", "first")] [@@bs.module "sourcebuster"];

external getFirstTrm : string = "trm" [@@bs.scope ("get", "first")] [@@bs.module "sourcebuster"];

external getCurrentTyp : string =
  "typ" [@@bs.scope ("get", "current")] [@@bs.module "sourcebuster"];

external getCurrentSrc : string =
  "src" [@@bs.scope ("get", "current")] [@@bs.module "sourcebuster"];

external getCurrentMdm : string =
  "mdm" [@@bs.scope ("get", "current")] [@@bs.module "sourcebuster"];

external getCurrentCmp : string =
  "cmp" [@@bs.scope ("get", "current")] [@@bs.module "sourcebuster"];

external getCurrentCnt : string =
  "cnt" [@@bs.scope ("get", "current")] [@@bs.module "sourcebuster"];

external getCurrentTrm : string =
  "trm" [@@bs.scope ("get", "current")] [@@bs.module "sourcebuster"];

external getUserVisits : string = "vst" [@@bs.scope ("get", "udata")] [@@bs.module "sourcebuster"];
