let component = ReasonReact.statelessComponent "Layout";

let make path::(path: string) children => {
  ...component,
  render: fun _ =>
    <div className="Container">
      <Header path />
      (ReasonReact.createDomElement "section" props::{"className": "Section"} children)
      <Footer />
    </div>
};
