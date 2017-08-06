let renderRoute path element =>
  ReactDOMRe.renderToElementWithId <Layout path> element </Layout> "app";

let renderDoc doc => <Doc> doc </Doc>;

let router =
  DirectorRe.makeRouter {
    "/": fun () => renderRoute "/" <Home />,
    "/installation": fun () => renderRoute "/installation" (renderDoc <Installation />),
    "/configuration": fun () => renderRoute "/configuration" (renderDoc <Configuration />),
    "/usage": fun () => renderRoute "/usage" (renderDoc <Usage />)
  };

SourcebusterRe.init ();

DirectorRe.init router "/";
