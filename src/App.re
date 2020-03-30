Css.(global("html, body", [margin(zero), padding(zero)]));


ReactDOMRe.renderToElementWithId(<Footer />, "app");
// using the the raw css which works.
// [@bs.val] external document: Js.t({..}) = "document";


// let style = document##createElement("style");
// document##head##appendChild(style);
// style##innerHTML #= FooterStyles.style;
// ReactDOMRe.renderToElementWithId(<Footers />, "app");
// ReactDOMRe.renderToElementWithId(<Footer2 />, "app");
