let str = ReasonReact.stringToElement;

module Decode = {
  let item = (json) =>
    Json.Decode.{
      Listing.listing_id: json |> field("listing_id", int),
      Listing.price: json |> field("price", string),
      Listing.title: json |> field("title", string)
    };
  let items = (json) => Json.Decode.(json |> array(item));
};

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
    (jsProps) => make(~items=jsProps##items |> Decode.items, [||])
  );
