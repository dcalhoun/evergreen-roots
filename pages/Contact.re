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
      <p>
        (
          str(
            "I love to hear from my customers. Please contact me using this form with any questions or comments. Wholesale inquires are welcomed."
          )
        )
      </p>
      <form>
        <div>
          <label htmlFor="name"> (str("Name")) </label>
          <input id="name" name="name" _type="text" />
        </div>
        <div>
          <label htmlFor="email"> (str("Email")) </label>
          <input id="email" name="email" _type="text" />
        </div>
        <div>
          <label htmlFor="message"> (str("Message")) </label>
          <textarea id="message" name="message" />
        </div>
        <Button _type="submit"> (str("Send Message")) </Button>
      </form>
    </div>
};

let default =
  ReasonReact.wrapReasonForJs(~component, (_jsProps) => make([||]));
