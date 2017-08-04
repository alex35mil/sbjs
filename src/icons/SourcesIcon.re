let component = ReasonReact.statelessComponent "SourcesIcon";

let make _ => {
  ...component,
  render: fun _ =>
    <Svg title="Sources">
      <path d="M9 11.5l1.5 1.5 5-5-5-5-1.5 1.5 3.5 3.5z" />
      <path d="M7 4.5l-1.5-1.5-5 5 5 5 1.5-1.5-3.5-3.5z" />
    </Svg>
};
