module Styles = {
  open Css;
  let waveAnimation =
    keyframes([
      (0, [transform(rotate(deg(0.)))]),
      (100, [transform(rotate(deg(0.)))]),
      (25, [transform(rotate(deg(20.)))]),
      (75, [transform(rotate(deg(-15.)))]),
    ]);

  let container =
    merge([
      style([
        display(`flex),
        height(`vh(100.)),
        width(`percent(100.)),
        lineHeight(`rem(1.3)),
        backgroundColor(black),
        fontFamilies([`custom("Menlo"), `custom("monospace")]),
      ]),
      // style([
      //   selector(
      //     "li p",
      //     [
      //       hover([
      //         animation(
      //           ~duration=300,
      //           ~iterationCount=infinite,
      //           waveAnimation,
      //         ),
      //       ]),
      //     ],
      //   ),
      // ]),
    ]);

  let ul =
    merge([
      style([
        display(`inlineGrid),
        gridAutoFlow(`row),
        gridGap(px(24)),
        justifyContent(`center),
        margin(`auto),
      ]),
      style([media("(min-width: 500px)", [gridAutoFlow(`column)])]),
    ]);

  let li =
      style([
        selector("li:lastChild",[gridColumn(1, 2), gridRow(1, 2)]),
        selector(
          "~ li p",
          [
            hover([
              animation(
                ~duration=300,
                ~iterationCount=infinite,
                waveAnimation,
              ),
            ]),
          ],
        ),
    ]);

  let a =
    style([
      color(white),
      textDecoration(`none),
      boxShadow(
        Shadow.box(
          ~inset=true,
          ~x=px(0),
          ~y=px(-1),
          ~blur=px(0),
          hsla(deg(0.), 0., 100., `num(0.4)),
        ),
      ),
      hover([
        boxShadow(
          Shadow.box(
            ~inset=true,
            ~x=px(0),
            ~y=em(-1.2),
            ~blur=px(0),
            hsla(deg(0.), 0., 100., `num(0.4)),
          ),
        ),
      ]),
    ]);
};
[@react.component]
let make = () =>
  <div className=Styles.container>
    <ul className=Styles.ul>
      <li className=Styles.li>
        <a className=Styles.a href="https://twitter.com/_idkjs">
          {React.string("Twitter")}
        </a>
      </li>
      <li className=Styles.li>
        <a className=Styles.a href="mailto:aarmand.inbox@gmail.com">
          {React.string("Email")}
        </a>
      </li>
      <li className=Styles.li>
        <a className=Styles.a href="https://github.com/idkjs">
          {React.string("Github")}
        </a>
      </li>
      <li> <p> {React.string({j|👋|j})} </p> </li>
    </ul>
  </div>;
