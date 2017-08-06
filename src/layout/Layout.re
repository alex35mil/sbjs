type retainedProps = {path: string};

let component = ReasonReact.statelessComponentWithRetainedProps "Layout";

let scrollTop: unit => unit = [%bs.raw {|
  function() { window.scrollTo(0, 0); }
|}];

let make path::(path: string) children => {
  ...component,
  retainedProps: {path: path},
  didUpdate: fun {oldSelf, newSelf} =>
    if (oldSelf.retainedProps.path !== newSelf.retainedProps.path) {
      scrollTop ()
    },
  render: fun _ =>
    <div className="Container">
      <Header path />
      (ReasonReact.createDomElement "section" props::{"className": "Section"} children)
      <Footer />
    </div>
};
