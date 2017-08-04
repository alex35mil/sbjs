let component = ReasonReact.statelessComponent "Header";

let make _ => {
  ...component,
  render: fun _ =>
    <header className="Header">
      <div className="HeaderMenu">
        <a href="#/" className="HeaderLink"> <HomeIcon /> </a>
        <a href="#/sourcebuster" className="HeaderLink">
          <span className="HeaderLinkRed"> (ReasonReact.stringToElement "source") </span>
          (ReasonReact.stringToElement "buster")
          <span className="HeaderLinkGray"> (ReasonReact.stringToElement ".js") </span>
        </a>
        <a href="#/sb-placer" className="HeaderLink">
          <span className="HeaderLinkRed"> (ReasonReact.stringToElement "sb") </span>
          (ReasonReact.stringToElement "-placer")
          <span className="HeaderLinkGray"> (ReasonReact.stringToElement ".js") </span>
        </a>
      </div>
      <a href="https://github.com/alexfedoseev/sourcebuster-js" className="HeaderLink">
        <GithubIcon />
      </a>
    </header>
};
