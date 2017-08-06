let component = ReasonReact.statelessComponent "Header";

let make path::(path: string) _ => {
  ...component,
  render: fun _ =>
    <header className="Header">
      <div className="HeaderMenu">
        <NavLink href="#/" path>
          <span className="HeaderLogoRed"> (ReasonReact.stringToElement "source") </span>
          (ReasonReact.stringToElement "buster")
          <span className="HeaderLogoGray"> (ReasonReact.stringToElement ".js") </span>
        </NavLink>
        <NavLink href="#/installation" path>
          (ReasonReact.stringToElement "Installation")
        </NavLink>
        <NavLink href="#/configuration" path>
          (ReasonReact.stringToElement "Configuration")
        </NavLink>
        <NavLink href="#/usage" path> (ReasonReact.stringToElement "Usage") </NavLink>
      </div>
      <NavLink href="https://github.com/alexfedoseev/sourcebuster-js" path>
        <GithubIcon className="SmallIcon" />
      </NavLink>
    </header>
};
