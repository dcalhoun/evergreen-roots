let str = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("Contact");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <div>
      <Next.Head>
        <title> (str("Contact - Evergreen Roots")) </title>
        <meta
          name="viewport"
          content="initial-scale=1.0, width=device-width"
        />
      </Next.Head>
      <Next.Link href="/"> <a> (str("Home")) </a> </Next.Link>
      <span> (str(" | Contact")) </span>
      <div> (str("Contact")) </div>
    </div>
};

let default =
  ReasonReact.wrapReasonForJs(~component, (_jsProps) => make([||]));
