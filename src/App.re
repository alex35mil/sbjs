let renderRoute element => ReactDOMRe.renderToElementWithId <Layout> element </Layout> "app";

let router =
  DirectorRe.makeRouter {
    "/": fun () => renderRoute <Home />,
    "/sourcebuster": fun () => renderRoute <Sourcebuster />,
    "/sb-placer": fun () => renderRoute <SbPlacer />
  };

DirectorRe.init router "/";
