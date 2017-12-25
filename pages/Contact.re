let str = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("Contact");

let make = (_children) => {
  let handleSubmit = (_) => Js.log("handleSubmit");
  {
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
        <Nav />
        <Heading> (str("Contact")) </Heading>
        <p>
          (
            str(
              "I love to hear from my customers. Please contact me using this form with any questions or comments. Wholesale inquires are welcomed."
            )
          )
        </p>
        <Form onSubmit=handleSubmit>
          <TextField name="name" label="Name" />
          <TextField name="email" label="Email" placeholder="you@email.com" />
          <TextArea
            name="message"
            label="Message"
            placeholder="How may we help?"
          />
          <Button _type="submit"> (str("Send Message")) </Button>
        </Form>
      </div>
  }
};

let default =
  ReasonReact.wrapReasonForJs(~component, (_jsProps) => make([||]));
