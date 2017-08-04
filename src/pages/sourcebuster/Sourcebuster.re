let component = ReasonReact.statelessComponent "Sourcebuster";

let make _ => {
  ...component,
  render: fun _ => <div> <h1> (ReasonReact.stringToElement "Sourcebuster") </h1> </div>
};
