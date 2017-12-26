type action =
  | SetListings(ListingData.items);

type state = {listings: ListingData.items};

let component = ReasonReact.reducerComponent("Store");

let make = (~render, _children) => {
  let setListings = ({ReasonReact.reduce}) =>
    reduce((payload) => SetListings(payload));
  {
    ...component,
    initialState: () => {listings: [||]},
    reducer: (action, _state) =>
      switch action {
      | SetListings(listings) => ReasonReact.Update(listings)
      },
    render: (_self) => <div> (ReasonReact.stringToElement("hi")) </div>
  }
};

let default =
  ReasonReact.wrapReasonForJs(
    ~component,
    (jsProps) => make(~render=jsProps##render, [||])
  );
