let component = ReasonReact.statelessComponent "SbPlacer";

let make _ => {
  ...component,
  render: fun _ => <div> <h1> (ReasonReact.stringToElement "SB Placer") </h1> </div>
};
