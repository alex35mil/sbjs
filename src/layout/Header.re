let component = ReasonReact.statelessComponent "Header";

let make _ => {
  ...component,
  render: fun _ =>
    <header className="Header">
      <div className="HeaderMenu">
        <a href="#/" className="HeaderLink">
          <span className="HeaderLogoRed"> (ReasonReact.stringToElement "source") </span>
          (ReasonReact.stringToElement "buster")
          <span className="HeaderLogoGray"> (ReasonReact.stringToElement ".js") </span>
        </a>
        <a href="#/installation" className="HeaderLink">
          (ReasonReact.stringToElement "Installation")
        </a>
        <a href="#/configuration" className="HeaderLink">
          (ReasonReact.stringToElement "Configuration")
        </a>
        <a href="#/usage" className="HeaderLink"> (ReasonReact.stringToElement "Usage") </a>
      </div>
      <a href="https://github.com/alexfedoseev/sourcebuster-js" className="HeaderLink">
        <GithubIcon className="SmallIcon" />
      </a>
    </header>
};
