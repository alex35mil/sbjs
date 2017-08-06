external html : string = "./docs/configuration.md" [@@bs.module];

let component = ReasonReact.statelessComponent "Configuration";

let make _ => {
  ...component,
  render: fun _ =>
    <div className="DocContent">
      <div className="DocMarkdown" dangerouslySetInnerHTML={"__html": html} />
      <div className="DocBottomNavigation">
        <Button href="#/installation" size=Button.Md color=Button.Gray>
          (ReasonReact.stringToElement {j|← Installation|j})
        </Button>
        <Button href="#/usage" size=Button.Md color=Button.Gray>
          (ReasonReact.stringToElement {j|Usage →|j})
        </Button>
      </div>
    </div>
};
