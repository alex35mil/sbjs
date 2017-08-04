let component = ReasonReact.statelessComponent "Footer";

let make _ => {
  ...component,
  render: fun _ => {
    let year = Js.Date.getFullYear (Js.Date.make ());
    <footer className="Footer">
      <div className="FooterContent">
        <div> (ReasonReact.stringToElement {j|© 2014–$year sbjs.rocks|j}) </div>
        <div className="FooterLinks">
          <a
            href="https://github.com/alexfedoseev/sourcebuster-js"
            className="FooterLink"
            title="Source code">
            <SourcesIcon className="SmallIcon" />
            <span className="FooterLinkText">
              (ReasonReact.stringToElement "sourcebuster.js")
            </span>
          </a>
          <a
            href="https://github.com/alexfedoseev/sb-placer"
            className="FooterLink"
            title="Source code">
            <SourcesIcon className="SmallIcon" />
            <span className="FooterLinkText"> (ReasonReact.stringToElement "sb-placer.js") </span>
          </a>
        </div>
      </div>
    </footer>
  }
};
