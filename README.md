# [reasonml-labs/bs-css](https://github.com/reasonml-labs/bs-css) emotion footer demo

This is just a port of this [codepen](https://codepen.io/julesforrest/pen/qLpgNB).

See discussion [here](https://github.com/reasonml-labs/bs-css/issues/190#issue-589683809)

![screenshot](./screenshot.png)

## Issues

Then hand is no repositioning to the left side of the array for some reason. It works if you use the following code to append the styles to the html head but no if the styles are defined in `Footer.re`:

```ocaml
[@bs.val] external document: Js.t({..}) = "document";

let style = document##createElement("style");
document##head##appendChild(style);
style##innerHTML #= FooterStyles.style;
ReactDOMRe.renderToElementWithId(<Footer/>, "app");
using the the raw css which works.
[@bs.val] external document: Js.t({..}) = "document";

let style = document##createElement("style");
document##head##appendChild(style);
style##innerHTML #= FooterStyles.style;

```

## Getting the `li` element styles working with the hand on the left side

To get the hand on the left side in either version, you have to add the `li:last-child` call onto the parent `ul` element like so;


```reason
  let ul =
    merge([
      style([
        display(`inlineGrid),
        gridAutoFlow(`row),
        gridGap(px(24)),
        justifyContent(`center),
        margin(`auto),
        selector("li:last-child", [gridColumn(1, 2), gridRow(1, 2)]),
      ]),
      style([media("(min-width: 500px)", [gridAutoFlow(`column)])]),
    ]);
```

If you put it on the `li` tag it doesn't register.

### Add `li` styles to `children` call on `ul`

see [`src/Footer.re](./src/Footer.re)

```reason
  let ul =
    merge([
      style([
        display(`inlineGrid),
        gridAutoFlow(`row),
        gridGap(px(24)),
        justifyContent(`center),
        margin(`auto),
        selector("li:last-child", [gridColumn(1, 2), gridRow(1, 2)]),
        children([
          hover([
            selector(
              "~ li p",
              [
                animation(
                  ~duration=300,
                  ~iterationCount=infinite,
                  waveAnimation,
                ),
              ],
            ),
          ]),
        ]),
      ]),
      style([media("(min-width: 500px)", [gridAutoFlow(`column)])]),
    ]);
```

### Add `li` styles to `li` definition and pass it to the element

see [`src/FooterLi.re](./src/FooterLi.re)

```reason
  let li =
    style([
      hover([
        selector(
          "~ li p",
          [
            animation(~duration=300, ~iterationCount=infinite, waveAnimation),
          ],
        ),
      ]),
    ]);
```

```reason
  let ul =
    merge([
      style([
        display(`inlineGrid),
        gridAutoFlow(`row),
        gridGap(px(24)),
        justifyContent(`center),
        margin(`auto),
        selector("li:last-child", [gridColumn(1, 2), gridRow(1, 2)]),
      ]),
      style([media("(min-width: 500px)", [gridAutoFlow(`column)])]),
    ]);
```
