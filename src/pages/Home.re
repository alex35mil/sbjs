let component = ReasonReact.statelessComponent "Home";

let make _children => {
  ...component,
  render: fun _ => <div> <h1> (ReasonReact.stringToElement "Home") </h1> </div>
};
