let renderRoute route => ReactDOMRe.renderToElementWithId <Layout> route </Layout> "app";

let renderDoc doc => <Doc> doc </Doc>;

let router =
  DirectorRe.makeRouter {
    "/": fun () => renderRoute <Home />,
    "/installation": fun () => renderRoute (renderDoc <Installation />),
    "/configuration": fun () => renderRoute (renderDoc <Configuration />),
    "/usage": fun () => renderRoute (renderDoc <Usage />)
  };

DirectorRe.init router "/";
