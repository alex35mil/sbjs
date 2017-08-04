let component = ReasonReact.statelessComponent "Layout";

let make children => {
  ...component,
  render: fun _ =>
    <div className="Container">
      <Header />
      (ReasonReact.createDomElement "section" props::{"className": "Section"} children)
      <Footer />
    </div>
};
