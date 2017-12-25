let str = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("Nav");

let make = (_children) => {
  let sNav = ReactDOMRe.Style.make(~fontFamily="sans-serif", ());
  {
    ...component,
    render: (_self) =>
      <nav style=sNav>
        <Next.Link href="/" prefetch=(Js.Boolean.to_js_boolean(true))>
          <a> (str("Home")) </a>
        </Next.Link>
        (str(" | "))
        <Next.Link href="/contact" prefetch=(Js.Boolean.to_js_boolean(true))>
          <a> (str("Contact")) </a>
        </Next.Link>
      </nav>
  }
};
