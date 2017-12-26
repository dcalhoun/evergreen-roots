let str = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("Contact");

let make = (_children) => {
  let handleSubmit = (_) => Js.log("handleSubmit");
  let sBody = ReactDOMRe.Style.make(~fontFamily="sans-serif", ());
  {
    ...component,
    render: (_self) =>
      <Layout>
        <Next.Head>
          <title> (str("Contact - Evergreen Roots")) </title>
          <meta
            name="viewport"
            content="initial-scale=1.0, width=device-width"
          />
        </Next.Head>
        <p style=sBody>
          (
            str(
              "We love to hear from our customers. Please contact us using this form with any questions or comments. Wholesale inquires are welcomed."
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
      </Layout>
  }
};

let default =
  ReasonReact.wrapReasonForJs(~component, (_jsProps) => make([||]));
