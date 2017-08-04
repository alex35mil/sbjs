let component = ReasonReact.statelessComponent "SourcebusterPageInstall";

let make _ => {
  ...component,
  render: fun _ => <div> (ReasonReact.stringToElement "Install") </div>
};
