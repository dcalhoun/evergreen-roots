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

type action =
  | SetListings(Listings.items);

type state = {
  status: string,
  items: Listings.items
};

let component = ReasonReact.reducerComponent("Index");

let make = (~items: Listings.items, ~status: string, _children) => {
  ...component,
  initialState: () => {status, items},
  reducer: (action, state) =>
    switch action {
    | SetListings(items) => ReasonReact.Update({...state, items})
    },
  didMount: (self) => {
    self.reduce((items) => SetListings(items), items);
    ReasonReact.NoUpdate
  },
  render: (self) =>
    <div>
      <Next.Head> <title> (str("Evergreen Roots")) </title> </Next.Head>
      <span> (str("Home | ")) </span>
      <Next.Link href="/contact"> <a> (str("Contact")) </a> </Next.Link>
      <About />
      (
        self.state.status == Status.idle ?
          <Loading /> : <Listings items=self.state.items />
      )
    </div>
};

let default =
  ReasonReact.wrapReasonForJs(
    ~component,
    (jsProps) =>
      make(
        ~status=jsProps##status,
        ~items=jsProps##items |> Decode.items,
        [||]
      )
  );
