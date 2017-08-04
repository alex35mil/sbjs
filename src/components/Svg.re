let component = ReasonReact.statelessComponent "Svg";

let make title::(title: string) className::(className: string) children => {
  ...component,
  render: fun _ =>
    ReasonReact.cloneElement
      <svg className viewBox="0 0 16 16" xmlns="http://www.w3.org/2000/svg">
        <title> (ReasonReact.stringToElement title) </title>
        (ReasonReact.createDomElement "g" props::(Js.Obj.empty ()) children)
      </svg>
      props::{"aria-labelledby": {j|$title-title|j}}
      [||]
};
