let component = ReasonReact.statelessComponent "SaveIcon";

let make ::className _ => {
  ...component,
  render: fun _ =>
    <Svg title="Save" className>
      <path
        d="M12.5 6h-3.5v-4h-2v4h-3.5l4.5 4zM11.611 8.322l-0.525 0.462c1.746 0.35 2.914 0.987 2.914 1.716 0 1.105-2.686 2-6 2s-6-0.895-6-2c0-0.728 1.168-1.366 2.914-1.716l-0.525-0.462c-2.604 0.495-4.389 1.508-4.389 2.678 0 1.657 3.582 3 8 3s8-1.343 8-3c0-1.17-1.785-2.183-4.389-2.678z"
      />
    </Svg>
};
