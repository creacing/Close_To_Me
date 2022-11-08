<template>
  <div class="layout">
    <!-- <Sidebar class="full-side" /> -->
    <Index :sideIndex="sideIndex" v-if="isShow" class="sideIndex full-side" />
    <!-- <MobileSide v-show="showIndex" :sideIndex="sideIndex" /> -->
    <div id="main" class="slide-up-big-in container pos-rel">
      <slot name="content"></slot>
    </div>
  </div>
</template>
<script setup>
import MobileSide from "@/components/MobileSide.vue";
import Pagination from "@/components/Pagination.vue";
import Sidebar from "@/components/Sidebar.vue";
import Index from "@/components/Index.vue";
import { useRoute } from "vue-router";
import { ref, watch, toRefs } from "vue";
import { store } from "@/stores/store.js";

const state = store();
const { showIndex } = toRefs(state);

const route = useRoute();

const sideIndex = ref([]);
const isShow = ref(false);
watch(
  () => route.path,
  (newPath, oldPath) => {
    isShow.value = newPath.startsWith("/article/") ? true : false;
  },
  { immediate: true }
);

watch(
  () => state.sideIndex,
  (newIndex, oldIndex) => {
    sideIndex.value = newIndex;
  },
  { immediate: true }
);
</script>
<style scoped>
.layout {
  margin: 0 auto;
  display: flex;
  justify-content: center;
  align-items: flex-start;
}

@media (min-width: 1200px) {
  .layout {
    width: 65rem;
  }
}

#main {
  background: linear-gradient(to top, var(--grey-0) 0, var(--grey-1) 20%)
    no-repeat top;
  box-shadow: 0 1.25rem 1rem 0.3125rem var(--body-bg-shadow);
  width: calc(100% - 15.75rem);
  min-height: 100vh;
  flex: auto;
}

#main .wrap {
  position: relative;
  padding: 1.25rem;
}

#main .wrap:nth-child(1) {
  margin-bottom: 1.25rem;
}

@media (max-width: 991px) {
  #main {
    width: 100%;
  }

  #main .wrap {
    padding: 0.625rem;
  }
}

@media (max-width: 767px) {
  #main .wrap {
    padding: 0.5rem;
  }
}

@media (max-width: 991px) {
  .sideIndex {
    display: none;
  }
}
@media (max-width: 767px) {
  .full-side {
    display: none;
  }
}
</style>



