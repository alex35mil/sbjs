let component = ReasonReact.statelessComponent "Button";

type color =
  | Blue
  | Gray;

type size =
  | Md
  | Lg;

let make size::(size: size) color::(color: color) href::(href: string) children => {
  ...component,
  render: fun _ => {
    let sizeClassName =
      switch size {
      | Md => "ButtonSizeMd"
      | Lg => "ButtonSizeLg"
      };
    let colorClassName =
      switch color {
      | Blue => "ButtonColorBlue"
      | Gray => "ButtonColorGray"
      };
    ReasonReact.createDomElement
      "a" props::{"href": href, "className": {j|Button $sizeClassName $colorClassName|j}} children
  }
};
