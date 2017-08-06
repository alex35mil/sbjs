external html : string = "./docs/installation.md" [@@bs.module];

let component = ReasonReact.statelessComponent "Installation";

let make _ => {
  ...component,
  render: fun _ =>
    <div className="DocContent">
      <div className="DocMarkdown" dangerouslySetInnerHTML={"__html": html} />
      <div className="DocBottomNavigation">
        <div />
        <Button href="#/configuration" size=Button.Md color=Button.Gray>
          (ReasonReact.stringToElement {j|Configuration →|j})
        </Button>
      </div>
    </div>
};
