module SourcebusterLayoutHeader = {
  let component = ReasonReact.statelessComponent "SourcebusterLayoutHeader";
  let make _ => {
    ...component,
    render: fun _ =>
      <div className="SectionHeader">
        <h1 className="SectionTitle">
          <a href="#/sourcebuster" className="SectionTitleLink">
            (ReasonReact.stringToElement "Sourcebuster")
          </a>
        </h1>
        <div className="SectionNavbar">
          <a href="#/sourcebuster/install" className="SectionNavbarLink">
            (ReasonReact.stringToElement "Install")
          </a>
          <a href="#/sourcebuster/configure" className="SectionNavbarLink">
            (ReasonReact.stringToElement "Configure")
          </a>
          <a href="#/sourcebuster/data" className="SectionNavbarLink">
            (ReasonReact.stringToElement "Data")
          </a>
          <a href="#/sourcebuster/changelog" className="SectionNavbarLink">
            (ReasonReact.stringToElement "Changelog")
          </a>
        </div>
      </div>
  };
};

let renderPage element =>
  <div className="SectionWrapper"> <SourcebusterLayoutHeader /> element </div>;
