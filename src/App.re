Css.(global("html, body", [margin(zero), padding(zero)]));
// using the the raw css which works.
[@bs.val] external document: Js.t({..}) = "document";

// let li_style = {j|
// li:last-child {
//   grid-column: 1 / 2;
//   grid-row: 1 / 2;
// }
// |j};

// let style = document##createElement("style");
// document##head##appendChild(style);
// style##innerHTML #= li_style;

ReactDOMRe.renderToElementWithId(<Footer />, "app");

ReactDOMRe.renderToElementWithId(<FooterLi />, "app");
