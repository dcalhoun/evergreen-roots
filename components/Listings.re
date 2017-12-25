let component = ReasonReact.statelessComponent("Listings");

let make = (~items: ListingData.items, _children) => {
  ...component,
  render: (_self) =>
    ReasonReact.arrayToElement(
      Array.map(
        (item: ListingData.item) =>
          <Listing key=(string_of_int(item.listing_id)) item />,
        items
      )
    )
};
