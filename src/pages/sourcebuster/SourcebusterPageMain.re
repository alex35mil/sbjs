let component = ReasonReact.statelessComponent "SourcebusterPageMain";

let make _ => {...component, render: fun _ => <div> (ReasonReact.stringToElement "Main") </div>};
