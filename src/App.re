let renderRoute element => ReactDOMRe.renderToElementWithId <Layout> element </Layout> "app";

let router =
  DirectorRe.makeRouter {
    /* Main */
    "/": fun () => renderRoute <Home />,
    /* Sourcebuster */
    "/sourcebuster": fun () => renderRoute (Sourcebuster.renderPage <SourcebusterPageMain />),
    "/sourcebuster/install": fun () =>
      renderRoute (Sourcebuster.renderPage <SourcebusterPageInstall />),
    "/sourcebuster/configure": fun () =>
      renderRoute (Sourcebuster.renderPage <SourcebusterPageConfigure />),
    "/sourcebuster/data": fun () => renderRoute (Sourcebuster.renderPage <SourcebusterPageData />),
    "/sourcebuster/changelog": fun () =>
      renderRoute (Sourcebuster.renderPage <SourcebusterPageChangelog />),
    /* SB-Placer */
    "/sb-placer": fun () => renderRoute <SbPlacer />
  };

DirectorRe.init router "/";
