let component = ReasonReact.statelessComponent "Doc";

let make children => {
  ...component,
  didMount: fun self => {
    PrismRe.highlightAll ();
    ReasonReact.SilentUpdate self.state
  },
  didUpdate: fun _ => PrismRe.highlightAll (),
  render: fun _ => ReasonReact.createDomElement "div" props::{"className": "Doc"} children
};
