let component = ReasonReact.statelessComponent "SourcebusterPageConfigure";

let make _ => {
  ...component,
  render: fun _ => <div> (ReasonReact.stringToElement "Configure") </div>
};
