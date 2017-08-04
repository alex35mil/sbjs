let component = ReasonReact.statelessComponent "SourcebusterPageChangelog";

let make _ => {
  ...component,
  render: fun _ => <div> (ReasonReact.stringToElement "Changelog") </div>
};
