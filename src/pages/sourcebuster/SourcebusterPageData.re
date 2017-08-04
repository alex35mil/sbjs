let component = ReasonReact.statelessComponent "SourcebusterPageData";

let make _ => {...component, render: fun _ => <div> (ReasonReact.stringToElement "Data") </div>};
