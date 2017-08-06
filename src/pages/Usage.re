external html : string = "./docs/usage.md" [@@bs.module];

let component = ReasonReact.statelessComponent "Usage";

let make _ => {
  ...component,
  render: fun _ =>
    <div className="DocContent">
      <div className="DocMarkdown" dangerouslySetInnerHTML={"__html": html} />
      <div className="DocBottomNavigation">
        <Button href="#/configuration" size=Button.Md color=Button.Gray>
          (ReasonReact.stringToElement {j|← Configuration|j})
        </Button>
      </div>
    </div>
};
