let str = ReasonReact.stringToElement;

let decodeItems = (json: Listings.items) =>
  Json.Decode.{
    /* TODO: How do I use a type from a different file? */
    listing_id: json |> field("listing_id", int),
    price: json |> field("price", int),
    title: json |> field("title", string)
  };

let yep = (json) => decodeItems(Js.Json.parseExn(json));

let component = ReasonReact.statelessComponent("Index");

let make = (~items: Listings.items, _children) => {
  ...component,
  render: (_self) =>
    <div>
      <Next.Head> <title> (str("Evergreen Roots")) </title> </Next.Head>
      <span> (str("Home | ")) </span>
      <Next.Link href="/contact"> <a> (str("Contact")) </a> </Next.Link>
      <About />
      (Array.length(items) > 0 ? <Listings items /> : <Loading />)
    </div>
};

let default =
  ReasonReact.wrapReasonForJs(
    ~component,
    (jsProps) => make(~items=yep(jsProps##items), [||])
  );
