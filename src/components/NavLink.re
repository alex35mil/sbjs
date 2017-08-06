let component = ReasonReact.statelessComponent "NavLink";

let make href::(href: string) path::(path: string) children => {
  ...component,
  render: fun _ => {
    let cleanHref = String.sub href 1 (String.length href - 1);
    let activeClassName = path !== "/" && cleanHref === path ? "NavLinkActive" : "";
    ReasonReact.createDomElement
      "a" props::{"href": href, "className": String.trim {j|NavLink $activeClassName|j}} children
  }
};
