<template>
  <div id="blog" class="flex-col pos-rel">
    <header id="header" class="pos-rel">
      <Nav />
    </header>
    <Wave id="waves" />
    <div id="sidebar">
      <Sidebar class :showSide="showSide" />
      <!-- <Sideindex :sideIndex="sideIndex" v-if="isShow" class="sideIndex" /> -->
    </div>
    <main>
      <LayOut>
        <template v-slot:content>
          <RouterView />
        </template>
      </LayOut>
    </main>
    <footer id="footer">
      <Footer />
    </footer>
  </div>
</template>  
<script setup>
import { RouterView } from "vue-router";
import Nav from "@/components/Nav.vue";
import Footer from "@/components/Footer.vue";
import Wave from "@/components/Wave.vue";
import LayOut from "@/views/LayOut.vue";
import Sidebar from "@/components/Sidebar.vue";
import Sideindex from "@/components/sideindex.vue";
import initAnime from "@/utils/clickAnime.js";
import { onMounted, ref, watch, toRefs } from "vue";
import { store } from "@/stores/store.js";
import { useRoute } from "vue-router";

const state = store();
const { showSide } = toRefs(state);

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

const showLoading = ref(false);

// register global animation
const init = () => {
  document.addEventListener("click", function (e) { initAnime(e); }, false);
}

onMounted(() => {
  init()
});


</script>
<style lang="scss" scoped>
#blog {
  min-height: 100%;
  min-width: 100%;

  #header {
    margin: 0 auto;
    width: 100%;
    height: 50vh;
    text-shadow: 0 0.2rem 0.3rem rgba(0, 0, 0, 0.5);
    color: var(--header-text-color);
  }

  #header a:hover {
    color: currentColor;
  }

  main {
    background: linear-gradient(to top,
        var(--body-bg-shadow) 0,
        var(--grey-1) 20%) no-repeat bottom;
    z-index: 999;
  }

  #footer {
    color: var(--grey-5);
    font-size: 0.875em;
    background: var(--body-bg-shadow);
  }
}
</style>
