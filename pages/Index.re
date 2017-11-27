let str = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("Index");

let make = (~items: Listings.items, _children) => {
  ...component,
  render: (_self) =>
    <div>
      <Next.Head> <title> (str("Evergreen Roots")) </title> </Next.Head>
      <span> (str("Home | ")) </span>
      <Next.Link href="/contact"> <a> (str("Contact")) </a> </Next.Link>
      <About />
      (List.length(items) > 0 ? <Listings items /> : <Loading />)
    </div>
};

/* TODO: How do I incorporate this into ReasonReact? */
let getInitialProps = () =>
  Js.Promise.(
    Endpoints.fetchListings()
    |> then_(Fetch.Response.json)
    |> then_((json) => Js.Json.decodeArray(json) |> resolve)
  );

let default =
  ReasonReact.wrapReasonForJs(
    ~component,
    (jsProps) => make(~items=jsProps##items, [||])
  );
