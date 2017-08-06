let component = ReasonReact.statelessComponent "Home";

let make _ => {
  ...component,
  render: fun _ =>
    <div className="Home">
      <div className="HomeHero">
        (ReasonReact.stringToElement "Your source is")
        <span className="HomeHeroSource">
          (
            ReasonReact.stringToElement (
              SourcebusterRe.getCurrentSrc === "(direct)" ?
                "direct visit" : SourcebusterRe.getCurrentSrc
            )
          )
        </span>
      </div>
      <div className="HomeSubHeroBlocks">
        <div className="HomeSubHeroBlock">
          <GlassesIcon className="LargeIcon" />
          <h2 className="HomeSubHeroBlockTitle">
            (ReasonReact.stringToElement "Track sources")
          </h2>
          <div className="HomeSubHeroBlockText">
            (ReasonReact.stringToElement "Find out the sources")
            <br />
            (ReasonReact.stringToElement "of your visitors")
          </div>
        </div>
        <div className="HomeSubHeroBlock">
          <ContentIcon className="LargeIcon" />
          <h2 className="HomeSubHeroBlockTitle">
            (ReasonReact.stringToElement "Show relevant content")
          </h2>
          <div className="HomeSubHeroBlockText">
            (ReasonReact.stringToElement "Show content")
            <br />
            (ReasonReact.stringToElement "depending on a source")
          </div>
        </div>
        <div className="HomeSubHeroBlock">
          <SaveIcon className="LargeIcon" />
          <h2 className="HomeSubHeroBlockTitle"> (ReasonReact.stringToElement "Save data") </h2>
          <div className="HomeSubHeroBlockText">
            (ReasonReact.stringToElement "Export data")
            <br />
            (ReasonReact.stringToElement "to email or CRM")
          </div>
        </div>
      </div>
      <div className="HomeTrackedDataContainer">
        <div className="HomeTrackedData">
          <div className="HomeTrackedDataVisit">
            <h3 className="HomeTrackedDataVisitTitle">
              (ReasonReact.stringToElement "First visit")
            </h3>
            <table className="HomeTrackedDataVisitTable">
              <tbody>
                <tr>
                  <td> (ReasonReact.stringToElement "type:") </td>
                  <td> (ReasonReact.stringToElement SourcebusterRe.getFirstTyp) </td>
                </tr>
                <tr>
                  <td> (ReasonReact.stringToElement "utm_source:") </td>
                  <td> (ReasonReact.stringToElement SourcebusterRe.getFirstSrc) </td>
                </tr>
                <tr>
                  <td> (ReasonReact.stringToElement "utm_medium:") </td>
                  <td> (ReasonReact.stringToElement SourcebusterRe.getFirstMdm) </td>
                </tr>
                <tr>
                  <td> (ReasonReact.stringToElement "utm_campaign:") </td>
                  <td> (ReasonReact.stringToElement SourcebusterRe.getFirstCmp) </td>
                </tr>
                <tr>
                  <td> (ReasonReact.stringToElement "utm_content:") </td>
                  <td> (ReasonReact.stringToElement SourcebusterRe.getFirstCnt) </td>
                </tr>
                <tr>
                  <td> (ReasonReact.stringToElement "utm_term:") </td>
                  <td> (ReasonReact.stringToElement SourcebusterRe.getFirstTrm) </td>
                </tr>
              </tbody>
            </table>
          </div>
          <div className="HomeTrackedDataVisit">
            <h3 className="HomeTrackedDataVisitTitle">
              (ReasonReact.stringToElement "Current visit: #")
              (ReasonReact.stringToElement SourcebusterRe.getUserVisits)
            </h3>
            <table className="HomeTrackedDataVisitTable">
              <tbody>
                <tr>
                  <td> (ReasonReact.stringToElement "type:") </td>
                  <td> (ReasonReact.stringToElement SourcebusterRe.getCurrentTyp) </td>
                </tr>
                <tr>
                  <td> (ReasonReact.stringToElement "utm_source:") </td>
                  <td> (ReasonReact.stringToElement SourcebusterRe.getCurrentSrc) </td>
                </tr>
                <tr>
                  <td> (ReasonReact.stringToElement "utm_medium:") </td>
                  <td> (ReasonReact.stringToElement SourcebusterRe.getCurrentMdm) </td>
                </tr>
                <tr>
                  <td> (ReasonReact.stringToElement "utm_campaign:") </td>
                  <td> (ReasonReact.stringToElement SourcebusterRe.getCurrentCmp) </td>
                </tr>
                <tr>
                  <td> (ReasonReact.stringToElement "utm_content:") </td>
                  <td> (ReasonReact.stringToElement SourcebusterRe.getCurrentCnt) </td>
                </tr>
                <tr>
                  <td> (ReasonReact.stringToElement "utm_term:") </td>
                  <td> (ReasonReact.stringToElement SourcebusterRe.getCurrentTrm) </td>
                </tr>
              </tbody>
            </table>
          </div>
        </div>
      </div>
    </div>
};
